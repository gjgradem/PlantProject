import { FirebaseProvider } from './../../providers/firebase/firebase';
import { Component } from '@angular/core';
import { NavController, NavParams } from 'ionic-angular';

@Component({
  selector: 'page-list',
  templateUrl: 'list.html'
})
export class ListPage {
  selectedItem: any;
  icons: string[];
  public items: string[];

  constructor(public navCtrl: NavController, public navParams: NavParams, public fprovider:FirebaseProvider) {
    this.fprovider.getPlants().then(res => {
      console.log(res.komkommer.information.name);
      this.items.push(res.komkommer.information.name);
    })
  }
}
