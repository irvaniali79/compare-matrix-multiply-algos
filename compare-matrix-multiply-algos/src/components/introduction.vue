<template>
  <div >

    <div class="row mt-3">
      <h1 class="p-0 m-0" style="color: rebeccapurple">Algorithm Design Project 2</h1>
    </div>

    <hr>

    <div class="row mt-2 p-0  ">

      <div class="col-4  ">
        <div class="row d-flex flex-column justify-content-center  ">
          <img src="../assets/images/photo_2021-04-03_18-53-42.df45ddac.jpg" style="align-self: center" >
        </div>

        <div class="row mt-2 p-0">
          <p class="m-0 p-0">

            <span style="font-weight: bold">Ali Irvani </span> (back) <br>
            <span style="color: coral">Known as </span> : <a v-b-tooltip.hover title="github link ..."  href="https://github.com/okabe-rintaru"> okabe-rintaru </a>
          </p>
        </div>
      </div>


      <div class="col-4  ">
        <div class="row d-flex flex-column justify-content-center ">
          <img src="../assets/images/photo_2021-04-03_22-37-0222.e303b007.jpg"  style="align-self: center">
        </div>
        <div class="row mt-2 p-0  ">
          <p class="m-0 p-0">
            <span style="font-weight: bold">Shahab Shafie </span>   (front + back) <br>
            <span style="color: coral"> Known as : </span><a v-b-tooltip.hover title="github link ..."  href="https://github.com/Shhb-Coder-1999" >  Shhb-Coder-1999 </a>
          </p>
        </div>
      </div>

        <div class="col-4  ">
        <div class="row d-flex flex-column justify-content-center ">
          <img src="../assets/images/photo_2021-05-15_14-57-00.c465dc30.jpg"   style="align-self: center">
        </div>
        <div class="row mt-2 p-0  ">
          <p class="m-0 p-0">
            <span style="font-weight: bold">Ali Hoseynian </span>   (back) <br>
            <span style="color: coral"> Known as : </span><a v-b-tooltip.hover title="github link ..."  href="https://github.com/Alihosseinian" >  Alihosseinian </a>
          </p>
        </div>
      </div>

    </div>

    <hr>

    <div class="row mt-2 px-3  ">
      <b-progress class=" w-100 p-0">
        <b-progress-bar :value="62" variant="success" animated striped  >vue</b-progress-bar>
        <b-progress-bar :value="28" variant="info"  animated striped  >c++</b-progress-bar>
        <b-progress-bar :value="5" variant="danger" animated striped   >html</b-progress-bar>
        <b-progress-bar :value="5" variant="warning" animated striped   >JS</b-progress-bar>
      </b-progress>

    </div>

    <hr>

    <div class="row mt-3">
      <p class="m-0 p-0">
         <span style="color: coral">Professor : </span> <a v-b-tooltip.hover title="linkedin..."  href="https://www.linkedin.com/in/mehdi-salkhordeh-haghighi-2a339a1a/"> Mr.Salkhorde haghighi</a> <br>
         <span style="color: coral">TA :  </span><a v-b-tooltip.hover title="linkedin..."  href="https://www.linkedin.com/in/payam-kiyani-pk3440/"> Mr.Kiani </a><br>
         <span style="color: coral">University : </span>   <a v-b-tooltip.hover title="uni site ..."  href="https://en.wikipedia.org/wiki/Sadjad_University_of_Technology"> Sadjad University of Technology </a> , Mashhad , Iran <br>
         <span style="color: coral">Released time : </span> 20 June 2021
        
      </p>
    </div>

    <hr>

    <div class="row mt-3 px-3">
      <p style="font-size: 10px" class="p-0 m-0">
       <span style="color: red">brief summary about project : </span>  <br>
        Directly applying the mathematical definition of matrix multiplication gives an algorithm that takes time on the order of n3 field operations to multiply two n × n matrices over that field (Θ(n3) in big O notation). Better asymptotic bounds on the time required to multiply matrices have been known since the Strassen's algorithm in the 1960s, but it is still unknown what the optimal time is (i.e., what the computational complexity of matrix multiplication is). As of December 2020, the matrix multiplication algorithm with best asymptotic complexity runs in O(n2.3728596) time, given by Josh Alman and Virginia Vassilevska Williams, however this algorithm is a galactic algorithm because of the large constants and cannot be realized practically.

      </p>
    </div>

    <hr class="mb-0">

    <div class="row mt-1 mb-2 ">
      <a href="https://github.com/okabe-rintaru/compare-matrix-multiply-algos" class="p-0 m-0"><img v-b-tooltip.hover title="see repository ... " src="../assets/images/GitHub-Mark.1fbf1eeb.png" class="p-0 m-0 github"></a>
<!--      <p style="font-size: 11px">-->
<!--        Project Src : <a href="https://github.com/okabe-rintaru/heap-Sorts-Comparison">https://github.com/okabe-rintaru/heap-Sorts-Comparison</a>-->
<!--      </p>-->
    </div>



  </div>
</template>




<script>
export default {
  data() {
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
img{
  height: 70px;
  width: auto;
  border-radius: 50%;
}
.github {
  height: 50px;
  width: auto;
  border-radius: 50%;
}
/*div {*/
/*  border: #2c3e50;*/
/*  border-style: solid;*/
/*  border-width: 1px;*/
/*}*/
p {
  font-size: 11px;
}
h1{
  font-size: 25px;
}
a{
  text-decoration: none;
  color: currentColor;
}
a:hover {
  color: rebeccapurple;
  text-decoration: underline;
}
</style>