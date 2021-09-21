char Fita[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link
      href="https://cdn.jsdelivr.net/npm/vuetify@2.x/dist/vuetify.min.css"
      rel="stylesheet"
    />
    <script src="https://cdn.jsdelivr.net/npm/vue@2.x/dist/vue.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/vuetify@2.x/dist/vuetify.js"></script>
    <script
      src="https://cdnjs.cloudflare.com/ajax/libs/axios/0.21.1/axios.min.js"
      integrity="sha512-bZS47S7sPOxkjU/4Bt0zrhEtWx0y0CRkhEp8IckzK+ltifIIE9EMIMTuT/mEzoIMewUINruDBIR/jJnbguonqQ=="
      crossorigin="anonymous"
    ></script>
    <title>Zonta</title>
  </head>
  <body>
    <div id="app">
      <v-app dark>
        <v-app-bar dark app shrink-on-scroll>
          <!-- <v-app-bar-nav-icon></v-app-bar-nav-icon> -->

          <v-toolbar-title>QUARTO</v-toolbar-title>

          <v-spacer></v-spacer>

          <v-btn icon>
            <v-icon>mdi-dots-vertical</v-icon>
          </v-btn>
        </v-app-bar>

        <v-main dark>
          <v-container>
            <v-card>
              <v-card-title>
                Escolha a cor do LED
              </v-card-title>
              <v-card-text>
                <v-row wrap rows>
                  <v-col
                    v-for="item in colorFita"
                    :key="item.color+item.label"
                    md="1"
                    xs="1"
                  >
                    <v-tooltip bottom>
                      <template v-slot:activator="{ on, attrs }">
                        <v-btn
                          v-bind="attrs"
                          v-on="on"
                          class="mx-2"
                          fab
                          dark
                          small
                          :color="item.color"
                          :title="item.label"
                          @click="onclickFita(item)"
                        >
                          <v-icon dark>
                            mdi-eyedropper-variant
                          </v-icon>
                        </v-btn>
                      </template>
                      <span>{{item.label}}</span>
                    </v-tooltip>
                  </v-col>
                </v-row>
              </v-card-text>

              <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn fab dark small @click="onOnOff('ledon')" color="green"
                  >ON</v-btn
                >
                <v-btn fab dark small @click="onOnOff('ledoff')" color="red"
                  >OFF</v-btn
                >
              </v-card-actions>
            </v-card>
            <!-- end card led -->
            <br />
            <v-divider></v-divider>
            <br />
            <v-card>
              <v-card-title>
                Escolha a cor do Quadro
              </v-card-title>
              <v-card-text>
                <v-row wrap rows>
                  <v-col
                    v-for="item in colorQuadro"
                    :key="item.color+item.label"
                    md="1"
                    xs="1"
                  >
                    <v-tooltip bottom>
                      <template v-slot:activator="{ on, attrs }">
                        <v-btn
                          v-bind="attrs"
                          v-on="on"
                          class="mx-2"
                          fab
                          dark
                          small
                          :color="item.color"
                          :title="item.label"
                          @click="onclickFita(item)"
                        >
                          <v-icon dark>
                            mdi-eyedropper-variant
                          </v-icon>
                        </v-btn>
                      </template>
                      <span>{{item.label}}</span>
                    </v-tooltip>
                  </v-col>
                </v-row>
              </v-card-text>
              <v-card-actions>
                <v-spacer></v-spacer>
                <v-btn fab dark small @click="onOnOff('quadroon')" color="green"
                  >ON</v-btn
                >
                <v-btn fab dark small @click="onOnOff('quadrooff')" color="red"
                  >OFF</v-btn
                >
              </v-card-actions>
            </v-card>
            <!-- end card quadro -->
            <br />
            <v-row wrap rows>
              <v-col
                v-for="(rele,index) in reles"
                :key="index+'_rele'"
                md="3"
                xs="6"
              >
                <v-card>
                  <v-card-title>{{rele.title}}</v-card-title>
                  <v-card-actions>
                    <v-spacer></v-spacer>
                    <v-btn
                      fab
                      dark
                      small
                      @click="onOnOff(rele.action.on)"
                      color="green"
                      >ON</v-btn
                    >
                    <v-btn
                      fab
                      dark
                      small
                      @click="onOnOff(rele.action.off)"
                      color="red"
                      >OFF</v-btn
                    >
                    <v-spacer></v-spacer>
                  </v-card-actions>
                </v-card>
              </v-col>
            </v-row>
            <!-- end reles -->
            <br />
          </v-container>
        </v-main>
      </v-app>
    </div>
    <script>
      function requisita(tipo) {
        let request = new XMLHttpRequest();
        url = `\\${tipo}`;
        console.log(url);
        request.open("POST", url, true);
        request.send();
      }
      new Vue({
        el: "#app",
        vuetify: new Vuetify({ theme: { dark: true } }),
        data() {
          return {
            colorFita: [
              { tipo: "ledazul", label: "azul", color: "#0000FF" },
              { tipo: "ledverdin", label: "verdin", color: "#00FFFF" },
              { tipo: "ledverde", label: "verde", color: "#008000" },
              { tipo: "ledroxo", label: "roxo", color: "#7B68EE" },
              { tipo: "ledroxao", label: "roxao", color: "#8A2BE2" },
              { tipo: "ledrosa", label: "rosa", color: "#FF00FF" },
              { tipo: "ledfesta", label: "croma", color: "#E0E0E0" },
              { tipo: "ledvermelho", label: "vermelho", color: "#FF0000" },
              { tipo: "ledbranco", label: "branco", color: "#FFFFFF" },
            ],
            colorQuadro: [
              { tipo: "quadroazul", label: "quadroazul", color: "#0000FF" },
              { tipo: "quadroverde", label: "quadroverde", color: "#008000" },
              { tipo: "quadroroxo", label: "quadroroxo", color: "#7B68EE" },
              {
                tipo: "quadrovermelho",
                label: "quadrovermelho",
                color: "#FF0000",
              },
            ],
            reles: [
              {
                title: "Bancada", // nome do rele
                action: {
                  on: "rele1on", // router para on
                  off: "rele1off", // router para off
                },
              },
              {
                title: "Face",
                action: {
                  on: "rele2on",
                  off: "rele2off",
                },
              },
              {
                title: "RELE 3",
                action: {
                  on: "rele3on",
                  off: "rele3off",
                },
              },
              {
                title: "RELE 4",
                action: {
                  on: "rele4on",
                  off: "rele4off",
                },
              },
            ],
          };
        },
        mounted() {},
        methods: {
          onclickFita(item) {
            requisita(item.tipo);
          },
          onOnOff(tipo) {
            requisita(tipo);
          },
        },
      });
    </script>
  </body>
</html>
)=====";