<?php
	$data = [];

	$data['key'] = "0xb69e83cecc4bcbd6";

	/**
	 * ==============================================================
	 * =========================== ALLOS ============================
	 * ==============================================================
	 */

	/**
	 * Respectez le format bande de schlags, n'écrivez que dans la partie de droite, après le '=>'
	 * Un numéro au bon format : '06 12 34 56 78'
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

	/**
	 * ==============================================================
	 * ======================= ACTIVITIES ===========================
	 * ==============================================================
	 */

	$data['activities'] = array(
		// [
		// 	'name' => 'La Cantina',
		// 	'description' => 'La Cantina de \'Ker des Étoiles\' est ouverte au I12-10. Il s\'agit d\'un espace convivial où tout le monde peuvent profiter de la nourriture proposé par la liste.'
		// ],
	);

	/**
	 * ==============================================================
	 * ========================= CHECKS =============================
	 * ==============================================================
	 */

	for ($i = 0; $i < 5; $i += 1) {

		foreach ($data['allos'][$i] as $name_allo => $allo) {
			$numero = $allo['numero'];
	
			if (preg_match('/^0[1-9]( \d\d){4}$/', $numero) != 1) {
				echo "Le numéro suivant ne respecte pas le format.\n";
				echo $numero . "\n";
				exit(1);
			}
		}
	}

	echo (json_encode($data, JSON_PRETTY_PRINT));
?>