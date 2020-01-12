import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonList,
  IonItem,
  IonLabel,
  IonCard} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from "react-router-dom";

const Home: React.FC<RouteComponentProps> = (props) => {
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

        Lorem ipsum dolor sit amet, consectetur adipisicing elit. Est eaque odit, impedit eius exercitationem dolorum libero quibusdam, sapiente repellat iusto ipsum, suscipit atque aspernatur quos quia et amet consequatur iure!

        <IonList>
          <IonItem routerLink='/present'>
            <IonLabel>
              <h2>Présentation de la liste</h2>
              <p>
                La présentation de la liste de manière générale et par pôle.
              </p>
            </IonLabel>
          </IonItem>
          <IonItem routerLink='/activities'>
            <IonLabel>
              <h2>Activités</h2>
              <p>
                Quelles sont les activités présentés par la liste sur le campus.
              </p>
            </IonLabel>
          </IonItem>
          <IonItem routerLink='/allos'>
            <IonLabel>
              <h2>Les allôs</h2>
              <p>
                La liste vous propose des allôs de qualité.
              </p>
            </IonLabel>
          </IonItem>
        </IonList>

      </IonContent>
    </IonPage>
  );
};

export default Home;
