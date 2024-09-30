import xml.etree.ElementTree as ET
from xml.dom import minidom

# Function to create GPX track from GPS points
def create_gpx_track(gps_points, output_file):
    # Create the root element <gpx> with the necessary attributes
    gpx = ET.Element("gpx", version="1.1", creator="GPS Generator", xmlns="http://www.topografix.com/GPX/1/1")
    
    # Add metadata (optional)
    metadata = ET.SubElement(gpx, "metadata")
    name = ET.SubElement(metadata, "name")
    name.text = "Generated GPX Track"
    
    # Add track element <trk>
    trk = ET.SubElement(gpx, "trk")
    trk_name = ET.SubElement(trk, "name")
    trk_name.text = "Sample Track"

    # Add track segment element <trkseg>
    trkseg = ET.SubElement(trk, "trkseg")
    
    # Add each GPS point as a track point <trkpt> within the <trkseg>
    for point in gps_points:
        print(point)
        lat, lon = point
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

output_gpx_file = "generated_track.gpx"  # Output GPX file name

# Generate GPX track
create_gpx_track(gps_points, output_gpx_file)

print(f"GPX file generated: {output_gpx_file}")
