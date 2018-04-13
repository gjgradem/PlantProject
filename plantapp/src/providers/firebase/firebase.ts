import { Injectable } from '@angular/core';
import { AngularFireDatabase } from 'angularfire2/database';

/*
  Generated class for the FirebaseProvider provider.

  See https://angular.io/guide/dependency-injection for more info on providers
  and Angular DI.
*/
@Injectable()
export class FirebaseProvider {

  constructor(public firebase: AngularFireDatabase) {
    console.log('Hello FirebaseProvider Provider');
  }

  getPlants() {
    return new Promise((resolve, reject) => {
      this.firebase.database.ref('/plants/').once('value').then(snapshot => {
        let plants = snapshot.val();
        resolve(plants);
      });
    });
  }

  // getFeedRows() {
  //   let result = this.firebase.database.ref('/plants/').once('value').then(function(snapshot) {
  //     var plantname = snapshot.val();
  //   });
  //   return result;
  // }

}
