import csv
import math

# Haversine formula to calculate the distance between two lat/lon points in meters
def haversine(lat1, lon1, lat2, lon2):
    R = 6371000  # Radius of Earth in meters
    phi1 = math.radians(lat1)
    phi2 = math.radians(lat2)
    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)
    
    a = math.sin(delta_phi / 2) ** 2 + math.cos(phi1) * math.cos(phi2) * math.sin(delta_lambda / 2) ** 2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    
    return R * c  # Distance in meters

def calculate_total_distance(csv_input, csv_output):
    # Open the input CSV file
    with open(csv_input, mode='r') as infile:
        reader = csv.reader(infile)
        waypoints = list(reader)

    # Check if the file has the correct headers and remove them
    if waypoints[0][0].lower() == 'latitude' and waypoints[0][1].lower() == 'longitude':
        waypoints = waypoints[1:]

    # Initialize cumulative distance and previous point
    total_distance = 0
    previous_point = None

    # Create a list to store the waypoints and distances
    output_data = [['Latitude', 'Longitude', 'Cumulative Distance (meters)']]

    # Iterate over each waypoint and calculate the total distance
    for row in waypoints:
        lat = float(row[0])
        lon = float(row[1])

        if previous_point:
            prev_lat, prev_lon = previous_point
            # Calculate the distance from the previous waypoint
            distance = haversine(prev_lat, prev_lon, lat, lon)
            total_distance += distance
        else:
            total_distance = 0  # No distance for the first point

        # Add the waypoint and cumulative distance to the output data
        output_data.append([lat, lon, total_distance])

        # Update previous point to current point
        previous_point = (lat, lon)

    # Write the output CSV with waypoints and cumulative distance
    with open(csv_output, mode='w', newline='') as outfile:
        writer = csv.writer(outfile)
        writer.writerows(output_data)

    print(f"Total distance calculated and written to {csv_output}")

# Example usage
input_csv = 'new_29.csv'  # Path to your input CSV file
output_csv = 'new_29_distance.csv'  # Path to the output CSV file

calculate_total_distance(input_csv, output_csv)
