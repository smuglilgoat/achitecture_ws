import xml.etree.ElementTree as ET
from xml.dom import minidom
import math

# Haversine formula to calculate the distance between two lat/lon points (in meters)
def haversine(lat1, lon1, lat2, lon2):
    R = 6371000  # Radius of Earth in meters
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)
    
    a = math.sin(delta_phi / 2) ** 2 + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2) ** 2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    
    return R * c

# Linear interpolation between two lat/lon points
def interpolate_points(lat1, lon1, lat2, lon2, num_points=10):
    lat1_rad, lon1_rad = math.radians(lat1), math.radians(lon1)
    lat2_rad, lon2_rad = math.radians(lat2), math.radians(lon2)

    interpolated_points = []
    for i in range(num_points):
        frac = i / (num_points - 1)
        lat_interp = lat1_rad * (1 - frac) + lat2_rad * frac
        lon_interp = lon1_rad * (1 - frac) + lon2_rad * frac
        interpolated_points.append((math.degrees(lat_interp), math.degrees(lon_interp)))
    
    return interpolated_points

# Circular interpolation (simplified) for curvature simulation
def circular_interpolation(p1, p2, p3, num_points=10):
    lat1, lon1 = p1
    lat2, lon2 = p2
    lat3, lon3 = p3
    
    # Start by linearly interpolating between p1 -> p2 and p2 -> p3 to simulate a curve around p2
    first_curve = interpolate_points(lat1, lon1, lat2, lon2, num_points)
    second_curve = interpolate_points(lat2, lon2, lat3, lon3, num_points)
    
    # Combine points from both segments but exclude the midpoint duplicate (p2)
    return first_curve[:-1] + second_curve

# Function to create a GPX track with curved paths around points
def create_gpx_curved_track(gps_points, output_file, num_interpolated_points=10):
    # Create the root element <gpx> with the necessary attributes
    gpx = ET.Element("gpx", version="1.1", creator="GPS Generator", xmlns="http://www.topografix.com/GPX/1/1")
    
    # Add metadata (optional)
    metadata = ET.SubElement(gpx, "metadata")
    name = ET.SubElement(metadata, "name")
    name.text = "Curved Loop GPX Path"
    
    # Add track element <trk>
    trk = ET.SubElement(gpx, "trk")
    trk_name = ET.SubElement(trk, "name")
    trk_name.text = "Curved Loop"

    # Add track segment element <trkseg>
    trkseg = ET.SubElement(trk, "trkseg")

    # Add interpolated curved segments between each triplet of points
    all_points = []
    num_points = len(gps_points)
    for i in range(num_points):
        p1 = gps_points[i - 1]  # Previous point
        p2 = gps_points[i % num_points]  # Current point
        p3 = gps_points[(i + 1) % num_points]  # Next point
        
        # Interpolate curved path between p1 -> p2 -> p3
        curved_segment = circular_interpolation(p1, p2, p3, num_interpolated_points)
        all_points.extend(curved_segment)

    # Add each point to GPX track
    for lat, lon in all_points:
        trkpt = ET.SubElement(trkseg, "trkpt", lat=str(lat), lon=str(lon))

    # Convert the tree to a string with proper indentation
    xml_str = ET.tostring(gpx, encoding='unicode')
    xml_pretty = minidom.parseString(xml_str).toprettyxml(indent="  ")

    # Write the formatted GPX to a file
    with open(output_file, "w") as f:
        f.write(xml_pretty)

# Example usage with four GPS points
gps_points = [
    (48.796671, 1.986849),  # Point 1: Lat, Lon
    (48.796292, 1.986454), 
    (48.795983, 1.987153), 
    (48.79635, 1.987532), 
    (48.796671, 1.986849)  # Point 1: Lat, Lon
]

output_gpx_file = "curved_gpx_track.gpx"

# Create GPX track with curved paths around the points
create_gpx_curved_track(gps_points, output_gpx_file, num_interpolated_points=20)

print(f"GPX file generated: {output_gpx_file}")
