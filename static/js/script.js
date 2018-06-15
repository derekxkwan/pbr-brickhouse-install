var d = document;

function submit_msg() {
    var http = new XMLHttpRequest();
    http.open("POST", "app.rb", true);
    http.setRequestHeader("Content-type","application/x-www-form-urlencoded");
    var params = d.getElementById("submit_form");
    http.send(params);
    http.onload = function() {
        alert(http.responseText);
    }
}
