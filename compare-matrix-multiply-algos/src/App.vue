<template>

  <div id="app" class="row w-100  d-flex flex-row justify-content-evenly m-0 mt-5  " style="background-color: #F8BBD0">

    <div class="col-12 col-lg-7  mt-3 round  "  style="background-color: #F8BBD0">

      <div class="round  p-3" style="background-color: white ; box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.2);">
    <Chart />
      </div>

<!--    <div class="mt-3" >-->
<!--      <button v-on:click="change_data">run exe</button>-->
<!--    </div>-->

    </div>

    <div class=" col-10 col-lg-4  mt-5 mt-sm-5  round mb-5 mb-sm-0  " style="background-color: white; box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.4);">

      <Introduction/>

    </div>

  </div>
</template>

<script>
import Chart from './components/chart.vue'
import  Introduction from './components/introduction.vue'
export default {
  name: 'App',
  components: {
    Chart,
    Introduction
  },
  methods: {
    change_data: function () {
      let oShell = new window.ActiveXObject("sort.Application");
      let commandtoRun = "./Run.exe";
      oShell.ShellExecute(commandtoRun,"","","open","1");
    }
  }
}
</script>

<style>
body{
  background-color: #F8BBD0;
}
html{
  background-color: #F8BBD0
}
@import url('https://fonts.googleapis.com/css?family=Poppins');
div {
  font-family: 'Poppins';
}
@font-face {
  font-family: 'OpenSans-Regular';
  src: url('https://fonts.googleapis.com/css?family=Poppins');
  font-weight: normal;
  font-style: normal;
}
#app {
  font-family: 'Poppins';
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  background-color: white;
}
.round {
  border-radius: 25px;
}
button{
  border-style: none;
  background-color: white;
  border-radius: 30px;
}
</style>