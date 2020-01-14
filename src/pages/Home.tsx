import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonList,
  IonItem,
  IonLabel,
  IonCard,
  IonButton} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from "react-router-dom";
import { CallNumber } from '@ionic-native/call-number/ngx';

import errorPage from '../modules/errorPage';
import getData from '../modules/getData';
import objToStrMap from '../modules/objToStrMap';

function callThisNumber(number : string) {
  (new CallNumber()).callNumber(number, true);
}

function genAlloDisplay(allo : any) {
  return (
    <div key={allo.name}>
      <h2>{allo.name}</h2>
      <p>{allo.description}</p>
      <IonButton expand="full" onClick={function(e) {callThisNumber(allo.numero)}}>Appeler (le {allo.numero})</IonButton>
    </div>
  );
}

function genAlloDomainDisplay(_alloDomain : any, index : number) {

  let names_allos = [];
  for (let key in _alloDomain) {
    names_allos.push(key);
  }
  let key = "_alloDomain" + index.toString();

  let alloDomain = objToStrMap(_alloDomain);
  console.log(alloDomain);

  let pahtToDomainPhoto = "assets/images/allo_" + index.toString() + ".jpg";

  return (
    <div key={key}>
      <IonCard>
        <img src={pahtToDomainPhoto} alt=""></img>
      </IonCard>
      {names_allos.map((allo) => {
        return genAlloDisplay(alloDomain.get(allo));
      })}
    </div>
  );
}

const Home: React.FC<RouteComponentProps> = (props) => {
  let _data = getData();
  if (_data == undefined) {
    return (errorPage());
  }

  let data = _data as Map<string, any>;

  console.log(data.get('allos'));

  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle>
            La Ker des Étoiles
          </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">

        <IonCard>
          <img src="assets/images/background_home.jpg" alt=""></img>
        </IonCard>

        <div>
          Lorem, ipsum dolor sit amet consectetur adipisicing elit. Non temporibus libero odit velit, cupiditate natus quidem accusamus ab consequuntur ullam? Ipsam, cumque quibusdam. Impedit quia voluptate distinctio quis, minima velit?
        </div>
  
        {
          data.get('allos').map((alloDomain : any, index : number) => {
            return genAlloDomainDisplay(alloDomain, index);
          })
        }

      </IonContent>
    </IonPage>
  );
};

export default Home;
