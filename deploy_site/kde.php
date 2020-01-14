<?php
	$data = [];

	$data['allos'] = [];

	/**
	 * Respectez le format bande de schlags, n'écrivez que dans la partie de droite, après le '=>'
	 * Un numéro au bon format : '+33 6 12 34 56 78'
	 */

	$data['allos']['alloforce'] = [
		'name' => 'AlloForce',
		'description' => 'Quand quelqu\'un a la flemme pour se lever et prendre un objet, il utilise la force de la liste pour le lui apporter.',
		'numero' => '+33 6 88 18 64 31'
	];

	foreach ($data['allos'] as $name_allo => $allo) {
		$numero = $allo['numero'];

		if (preg_match('/^(\+33 |0)[1-9]( \d\d){4}$/', $numero) != 1) {
			echo "Le numéro suivant ne respecte pas le format\n";
			echo $numero . "\n";
			exit(1);
		}
	}

	echo (json_encode($data, JSON_PRETTY_PRINT));
?>
