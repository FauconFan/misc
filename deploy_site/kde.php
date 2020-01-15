<?php
	$data = [];

	$data['key'] = "0xb69e83cecc4bcbd6";

	/**
	 * Respectez le format bande de schlags, n'écrivez que dans la partie de droite, après le '=>'
	 * Un numéro au bon format : '+33 6 12 34 56 78'
	 * 
	 * 0 => Shotgun
	 * 1 => Éphémère
	 * 2 => Fun
	 * 3 => Bouffe
	 * 4 => Voiture
	 */

	$data['allos'] = array (
		0 => [],
		1 => [],
		2 => [],
		3 => [],
		4 => []
	);

	$data['allos'][2]['alloforce'] = [
		'name' => 'AlloForce',
		'description' => 'Quand quelqu\'un a la flemme pour se lever et prendre un objet, il utilise la force de la liste pour le lui apporter.',
		'numero' => '+33 6 88 18 64 31'
	];

	$data['allos'][2]['allolaterre'] = [
		'name' => 'Allo La Lune',
		'description' => 'Lorem ipsum.',
		'numero' => '+33 6 88 18 64 31'
	];

	for ($i = 0; $i < 5; $i += 1) {

		foreach ($data['allos'][$i] as $name_allo => $allo) {
			$numero = $allo['numero'];
	
			if (preg_match('/^(\+33 |0)[1-9]( \d\d){4}$/', $numero) != 1) {
				echo "Le numéro suivant ne respecte pas le format\n";
				echo $numero . "\n";
				exit(1);
			}
		}
	}

	echo (json_encode($data, JSON_PRETTY_PRINT));
?>
