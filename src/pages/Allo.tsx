import {
	IonRouterOutlet
} from '@ionic/react';
import React from 'react';
import { Route } from 'react-router';
import AlloGeneral from './AlloGeneral';
import AlloSpec from './AlloSpec';

const Allo: React.FC = () => {
	return (
		<IonRouterOutlet>
			<Route exact path="/allos" component={AlloGeneral} />
			<Route path="/allos/:id" component={AlloSpec} />
		</IonRouterOutlet>
	);
};
export default Allo;
