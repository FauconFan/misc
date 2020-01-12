// function delay(ms: number) {
//     return new Promise( resolve => setTimeout(resolve, ms) );
// }

export function getData() {
	let xhr = new XMLHttpRequest();

	// open the request with the verb and the url
	xhr.open('GET', 'https://jpriou.fr/index.php?purpose=kde', false);

	// xhr.timeout = 2000;

	xhr.onload = function() {
		console.log(xhr);
		console.log(xhr.responseText);
	}

	xhr.ontimeout = function() {
		console.log('timeout');
	}

	// send the request
	xhr.send(null);

	return xhr.responseText;
}
