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
    (48.796634,1.986936),
    (48.79665,1.986899),
    (48.796655,1.986851),
    (48.796637,1.986812),
    (48.796614, 1.98678),
    (48.796587, 1.986752),
    (48.796342, 1.986505),
    (48.796316, 1.986488),
    (48.796292, 1.986485),
    (48.796269, 1.986501),
    (48.796246, 1.986549),
    (48.79611, 1.986854),
    (48.796017, 1.987052),
    (48.796006, 1.987122),
    (48.796016, 1.987173),
    (48.79604, 1.987207),
    (48.796072, 1.987247),
    (48.79627, 1.987488),
    (48.79629, 1.987507),
    (48.796321, 1.987519),
    (48.796351, 1.98751),
    (48.796386, 1.987464),
    (48.796483, 1.987259),
    (48.796634,1.986936)
]

output_gpx_file = "generated_track.gpx"  # Output GPX file name

# Generate GPX track
create_gpx_track(gps_points, output_gpx_file)

print(f"GPX file generated: {output_gpx_file}")
