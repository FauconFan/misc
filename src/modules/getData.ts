import objToStrMap from './objToStrMap';

// function delay(ms: number) {
//     return new Promise( resolve => setTimeout(resolve, ms) );
// }

function getData() : Map<string, any> | undefined {
	let xhr = new XMLHttpRequest();

	// open the request with the verb and the url
	xhr.open('GET', 'https://jpriou.fr/index.php?purpose=kde', false);

	// xhr.timeout = 2000;

	xhr.onload = function() {}

	xhr.ontimeout = function() {
		console.log('timeout');
	}

	// send the request
	xhr.send(null);

	let r1 = xhr.responseText;
	
	try {
		let r2 = JSON.parse(r1);

		if (r2.key === "0xb69e83cecc4bcbd6") {
			return (objToStrMap(r2));
		}
	} catch (error) {}

	return undefined;
}

export default getData;
