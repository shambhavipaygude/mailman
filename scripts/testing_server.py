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

    print("Form Data:")
    for key, value in request.args.items():
        print(f"{key}: {value}")

    if request.is_json:
        print("JSON Data:")
        print(request.get_json())

    # Build a complex response with many headers
    response = jsonify({
        "message": "GET request successful",
        "status": "OK",
        "data": {
            "info": "This is a complex response",
            "details": "You can add more content here"
        },
        "wtf": {
            "info": "This is a shit response",
            "details": "You can notewkniewlkr content here"
        }
    })

    # Add multiple custom headers to the response
    response.headers['X-Custom-Header'] = 'This is a custom header'
    response.headers['X-API-Version'] = '1.0.0'
    response.headers['X-Request-ID'] = '1234567890'
    response.headers['X-Server-Time'] = '2024-12-15T12:00:00Z'
    response.headers['X-Content-Type'] = 'application/json'
    response.headers['X-Additional-Info'] = 'More headers can be added as needed'

    return response

@app.route('/', methods=['POST'])
def handle_post():
    print("Form Data:")
    for key, value in request.form.items():
        print(f"{key}: {value}")

    print("Raw Data:")
    print(request.data.decode('utf-8'))

    data = request.get_json()  # Parse the incoming JSON data
    if data:
        return jsonify({"message": "POST request received", "data": data})
    else:
        return jsonify({"message": "Invalid JSON data"}), 400

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=8080, debug=True)