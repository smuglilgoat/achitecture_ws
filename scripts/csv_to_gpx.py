import csv
import xml.etree.ElementTree as ET

# Function to create a GPX file from a list of coordinates
def csv_to_gpx(csv_filename, gpx_filename):
    # Create the root element of the GPX file
    gpx = ET.Element('gpx', version="1.1", creator="csv_to_gpx_script")
    gpx.set('xmlns', "http://www.topografix.com/GPX/1/1")
    gpx.set('xmlns:xsi', "http://www.w3.org/2001/XMLSchema-instance")
    gpx.set('xsi:schemaLocation', "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd")
    
    # Create a track element (trk)
    trk = ET.SubElement(gpx, 'trk')
    ET.SubElement(trk, 'name').text = "Track from CSV"

    # Create a track segment (trkseg)
    trkseg = ET.SubElement(trk, 'trkseg')

    # Open and read the CSV file
    with open(csv_filename, 'r') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header row if present
        
        for row in reader:
            if len(row) >= 2:  # Ensure there's latitude and longitude in the row
                lat, lon = row[0], row[1]
                
                # Create a track point (trkpt) in the track segment
                trkpt = ET.SubElement(trkseg, 'trkpt', attrib={'lat': lat, 'lon': lon})

    # Convert the ElementTree to a string and write to the GPX file
    tree = ET.ElementTree(gpx)
    tree.write(gpx_filename, encoding='utf-8', xml_declaration=True)

# # Convert csv to gpx
# track_csv_filename = "track.csv"
# track_gpx_filename = "track.gpx"
# csv_to_gpx(track_csv_filename, track_gpx_filename)
# print(f"GPX file '{track_gpx_filename}' has been created from CSV '{track_csv_filename}'")

# # Convert csv to gpx
# MEd_csv_filename = "MEd.csv"
# MEd_gpx_filename = "MEd.gpx"
# csv_to_gpx(MEd_csv_filename, MEd_gpx_filename)
# print(f"GPX file '{MEd_gpx_filename}' has been created from CSV '{MEd_csv_filename}'")

# # Convert csv to gpx
# MEg_csv_filename = "MEg.csv"
# MEg_gpx_filename = "MEg.gpx"
# csv_to_gpx(MEg_csv_filename, MEg_gpx_filename)
# print(f"GPX file '{MEg_gpx_filename}' has been created from CSV '{MEg_csv_filename}'")

# Convert csv to gpx
# GPSd_csv_filename = "GPSd.csv"
# GPSd_gpx_filename = "GPSd.gpx"
# csv_to_gpx(GPSd_csv_filename, GPSd_gpx_filename)
# print(f"GPX file '{GPSd_gpx_filename}' has been created from CSV '{GPSd_csv_filename}'")

# Convert csv to gpx
GPSg_csv_filename = "GPSd29.csv"
GPSg_gpx_filename = "GPSd29.gpx"
csv_to_gpx(GPSg_csv_filename, GPSg_gpx_filename)
print(f"GPX file '{GPSg_gpx_filename}' has been created from CSV '{GPSg_csv_filename}'")

GPSg_csv_filename = "GPSg29.csv"
GPSg_gpx_filename = "GPSg29.gpx"
csv_to_gpx(GPSg_csv_filename, GPSg_gpx_filename)
print(f"GPX file '{GPSg_gpx_filename}' has been created from CSV '{GPSg_csv_filename}'")