import xml.etree.ElementTree as ET
import csv

def gpx_to_csv(gpx_file, output_csv):
    # Parse the GPX file
    tree = ET.parse(gpx_file)
    root = tree.getroot()

    # GPX namespace
    ns = {'default': 'http://www.topografix.com/GPX/1/1'}

    # Open the CSV file for writing
    with open(output_csv, mode='w', newline='') as csv_file:
        csv_writer = csv.writer(csv_file)
        
        # Write header
        csv_writer.writerow(['Latitude', 'Longitude'])

        # Find all waypoints (trkpt or wpt in GPX)
        for trkpt in root.findall(".//default:trkpt", ns):
            lat = trkpt.attrib['lat']
            lon = trkpt.attrib['lon']
            csv_writer.writerow([lat, lon])
    
    print(f"Waypoints have been written to {output_csv}")

# Example usage
gpx_file = 'new_29.gpx'  # Path to your GPX file
output_csv = 'new_29.csv'  # Path to the output CSV file

gpx_to_csv(gpx_file, output_csv)
