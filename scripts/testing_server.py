from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/', methods=['GET'])
def handle_get():
    print(f"Method: {request.method}")
    print(f"URL: {request.url}")

    print("Headers:")
    for header, value in request.headers.items():
        print(f"{header}: {value}")

    print("Query Parameters:")
    for key, value in request.args.items():
        print(f"{key}: {value}")

    if request.is_json:
        print("JSON Data:")
        print(request.get_json())

    print("\n")
    return "Request Details Printed!"


@app.route('/', methods=['POST'])
def handle_post():
    data = request.get_json()  # Parse the incoming JSON data
    if data:
        return jsonify({"message": "POST request received", "data": data})
    else:
        return jsonify({"message": "Invalid JSON data"}), 400

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)
