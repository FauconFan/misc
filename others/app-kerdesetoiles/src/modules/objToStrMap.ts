function objToStrMap(obj : any) {
	let strMap = new Map();
	for (let k of Object.keys(obj)) {
	  strMap.set(k, obj[k]);
	}
	return strMap;
}

export default objToStrMap;
