import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonCard,
  IonButton,
  IonRefresher,
  IonRefresherContent,
  IonText,
  IonToggle,
  IonRouterLink,
  IonLabel,
  IonItemDivider,
  IonIcon,
  IonList,
  IonItem} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from "react-router-dom";
import { CallNumber } from '@ionic-native/call-number/ngx';

import errorPage from '../modules/errorPage';
import getData from '../modules/getData';
import objToStrMap from '../modules/objToStrMap';

const namesOfIndex : string[] = [
  "Les allos shotguns",
  "Les allos éphémères",
  "Les allos funs",
  "Les allos bouffe",
  "Les allos force"
];

function callThisNumber(number : string) {
  (new CallNumber()).callNumber(number, true);
}

function scrollTo(element : string) {
  let htmlEl = document.getElementById(element)!;
  htmlEl.scrollIntoView(true);
}

function genAlloDisplay(allo : any) {
  let title = allo.name;

  if (allo.prix > 0) {
    title += " (" + allo.prix.toString() + " €)";
  }

  return (
    <div key={allo.name} className="ion-padding-top">
      <h2>{title}</h2>
      <p>{allo.description}</p>
      <IonButton expand="full" onClick={function() {callThisNumber(allo.numero)}}>Appeler (le {allo.numero})</IonButton>
    </div>
  );
}

function genSubMenu(allos : any) {

  return (
    <div key="summary_allo">
      <IonList>
        {allos.map((allo : any, index : number) => {
          if (Object.keys(allo).length > 0) {
            let nameOnClick = "alloDomain_" + index.toString();
            console.log(nameOnClick);
            return (
              <IonItem>
                <IonLabel onClick={() => {scrollTo(nameOnClick);}}>
                  <IonTitle>{namesOfIndex[index]}</IonTitle>
                </IonLabel>
              </IonItem>);
          }
          return (<> </>);
        })}
      </IonList>
    </div>);
}

function genAlloDomainDisplay(_alloDomain : any, index : number) {
  let names_allos = [];
  for (let key in _alloDomain) {
    names_allos.push(key);
  }

  if (names_allos.length == 0) {
    return (<> </>);
  }

  let key = "alloDomain_" + index.toString();

  let alloDomain = objToStrMap(_alloDomain);

  let pahtToDomainPhoto = "assets/images/allo_" + index.toString() + ".jpg";

  return (
    <div key={key} id={key}>
      <h1 className="ion-text-center">{namesOfIndex[index]}</h1>
      <IonCard>
        <img src={pahtToDomainPhoto} alt=""></img>
      </IonCard>
      {names_allos.map((allo) => {
        return genAlloDisplay(alloDomain.get(allo));
      })}
    </div>
  );
}

function genActivitiesDisplay(activities : any) {
  let genActivityDisplay = (activity : any) => {
    return (
      <div key={activity.name}>
        <h2>{activity.name}</h2>
        <p>{activity.description}</p>
      </div>
    );
  }

  if (activities.length == 0) {
    return (
      <p key="no_activities">Pas d'activité prévue pour l'instant.</p>
    );
  }

  return (activities.map((activity : any, index : number) => {
    return (genActivityDisplay(activity));
  }));
}

const Home: React.FC<RouteComponentProps> = () => {
  let _data = getData();
  if (_data == undefined) {
    return (errorPage());
  }

  const _el = document.querySelector('#root');
  const el = _el as HTMLInputElement;
  el.style.setProperty('--ion-background-color', 'black');
  el.style.setProperty('--ion-text-color', 'white');

  let data = _data as Map<string, any>;

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
          
        <IonRefresher slot="fixed" onIonRefresh={() => {window.location.reload()}}>
          <IonRefresherContent key="refresher" pullingIcon="arrow-dropdown" pullingText="Tirer vers le bas pour mettre à jour" refreshingText="Mise à jour">
          </IonRefresherContent>
        </IonRefresher>

        <div className="ion-text-center">
          <img src="assets/images/logo.png" alt="" width="128px" height="128px"></img>
        </div>

        <IonItemDivider>
          <IonLabel>
            Sommaire
          </IonLabel>
        </IonItemDivider>

        <div key="summary">
          <IonList>
            <IonItem>
              <IonLabel onClick={() => {scrollTo('I-allos');}}>
                <IonTitle>Les Allos</IonTitle>
              </IonLabel>
            </IonItem>
            <IonItem>
              <IonLabel onClick={() => {scrollTo('II-activite');}}>
                <IonTitle>Les activités</IonTitle>
              </IonLabel>
            </IonItem>
            <IonItem>
              <IonLabel onClick={() => {scrollTo('III-apropos');}}>
                <IonTitle>À propos</IonTitle>
              </IonLabel>
            </IonItem>
          </IonList>
        </div>

        <IonIcon name="arrow-dropright"></IonIcon>

        <IonItemDivider>
          <IonLabel>
            Présentation de l'application
          </IonLabel>
        </IonItemDivider>

        <div key="text_bienvenue">
          <p>Bonjour jeune Jedi.</p>
          <p>Tu as réussi l’install party, que les campagnes commencent ! Et qui dit campagnes, dit allo.</p>
          <p>Cette application te permet de manier la force, ne la sens-tu pas ? La force de nous appeler en cliquant juste sur le bouton du allô que tu souhaites ?</p>
          <p>Mais prends garde jeune jedi, tu n’arrives pas encore à maîtriser ta force, un simple clique sur le bouton et ton téléphone appèlera. <br></br>Alors ton allô à toi arrivera et sur Lydia tu payeras.</p>
          <p>Le côté obsker se permet parfois d’empêcher les mises à jour. Pour les faire, il te suffit de swiper vers le bas comme une page web. Seulement les mises à jour sont parfois fébriles, les numéros ne seront plus toujours d’actualité, ne sois pas surpris.</p>
          <p>Bonne campagne,</p>
          <p>La ker des étoiles</p>
        </div>
  
        <IonItemDivider>
          <IonLabel id="I-allos">
            Les allos
          </IonLabel>
        </IonItemDivider>

        {
          genSubMenu(data.get('allos'))
        }

        {
          data.get('allos').map((alloDomain : any, index : number) => {
            return genAlloDomainDisplay(alloDomain, index);
          })
        }

        <h1 id="II-activite">II - Activités</h1>

        {genActivitiesDisplay(data.get('activities'))}

        <h1 id="III-apropos">III - À propos</h1>

        <p>Cette application a été développé par la liste 'La Ker des Étoiles' avec pour développeur principal Joseph Priou, avec l'aide de Corentin Hubert, ainsi que toute l'équipe technique de la liste.</p>
        <p>Nous aimerions nous excuser pour la gène occasionnée par l'installation de l'application qui n'a pas pu se faire sur Google Play ou sur l'App Store dû à un manque de temps.</p>
        <p></p>
        <p>Force à 'La Ker des Étoiles'</p>
        
        
      </IonContent>
    </IonPage>
  );
};

export default Home;
