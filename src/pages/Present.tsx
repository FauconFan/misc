import {
	IonRouterOutlet
} from '@ionic/react';
import React from 'react';
import { Route } from 'react-router';
import PresentGeneral from './PresentGeneral';
import PresentPole from './PresentPole';

const Present: React.FC = () => {
	return (
		<IonRouterOutlet>
			<Route exact path="/present" component={PresentGeneral} />
			<Route path="/present/:id" component={PresentPole} />
		</IonRouterOutlet>
	);
};
export default Present;
