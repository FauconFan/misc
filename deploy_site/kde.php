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

	// $data['allos'][0]['allococktail'] = [
	// 	'name' => 'AlloCocktail',
	// 	'description' => 'Comment ça ?! Tu es à sec ?',
	// 	'prix' => 0,
	// 	'numero' => '06 88 18 64 31'
	// ];

	// $data['allos'][0]['alloraclette'] = [
	// 	'name' => 'AlloRaclette',
	// 	'description' => 'Si le premier à appeler tu es, l\'appareil à raclette et les ingrédients tu gagneras.',
	// 	'prix' => 0,
	// 	'numero' => '06 88 18 64 31'
	// ];

	$data['allos'][1]['allolaterre'] = [
		'name' => 'Allo La Terre',
		'description' => 'Tu as un ami fan de jardinage ? Appelle et on remplira sa chambre de terre.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][1]['allolotterie'] = [
		'name' => 'AlloLotterie',
		'description' => 'Pour chaque burger acheté, tu as une chance supplémentaire de gagner le gros lot.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][1]['allolamer'] = [
		'name' => 'AlloLaMer',
		'description' => 'Il fait chaud non ? On vient renverser de l\'eau de mer sur la personne de ton choix.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][1]['allosagesse'] = [
		'name' => 'AlloSagesse',
		'description' => 'On t\'envoie maître Yoda pour philosopher avec toi.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][2]['alloambiance'] = [
		'name' => 'AlloAmbiance',
		'description' => 'Tu t\'ennuies ? Appelle-nous, notre équipe saura te divertir et apaiser ta soif.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][2]['alloforce'] = [
		'name' => 'AlloForce',
		'description' => 'Si tu as la flemme de te lever pour prendre un objet, utilise la force de la liste pour te l\'apporter.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][2]['alloeauchaude'] = [
		'name' => 'AlloEauChaude',
		'description' => 'On t\'amène de la tisane, du chocolat et un plaid.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][2]['alloreveildelaforce'] = [
		'name' => 'AlloReveilDeLaForce',
		'description' => 'Difficile de se lever un lendemain de soirée... Nous te proposons le meilleur des réveils pour y remédier.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][3]['alloburger'] = [
		'name' => 'AlloBurger',
		'description' => 'Un petit creux ? La Ker des étoiles vous propose son délicieux burger livré chez vous.',
		'prix' => 1,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][3]['allocrêpe'] = [
		'name' => 'AlloCrêpe',
		'description' => 'La seule vraie question est de savoir si tu la veux au chocolat, au sucre ou à la confiture.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][3]['allohotdog'] = [
		'name' => 'AlloHotdog',
		'description' => 'Encore faim ?',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][4]['allohyperespace'] = [
		'name' => 'AlloHyperEspace',
		'description' => 'Si tu as besoin de te déplacer, nos chauffeurs se feront un plaisir de te conduire dans leur X-wing.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][4]['alloménage'] = [
		'name' => 'AlloMénage',
		'description' => 'Un coup de balai à passer ? Pas de problème : on s\'en occupe.',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	$data['allos'][4]['allovaisselle'] = [
		'name' => 'AlloVaisselle',
		'description' => 'Pourquoi faire sa vaisselle lorsque d\'autres peuvent le faire à notre place...',
		'prix' => 0,
		'numero' => '06 88 18 64 31'
	];

	/**
	 * ==============================================================
	 * ======================= ACTIVITIES ===========================
	 * ==============================================================
	 */

	$data['activities'] = array(
		[
			'name' => 'La Cantina',
			'description' => 'La Cantina de \'Ker des Étoiles\' est ouverte au I12-10. Il s\'agit d\'un espace convivial où tout le monde peuvent profiter de la nourriture proposé par la liste.'
		],
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