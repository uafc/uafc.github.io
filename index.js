const hero = document.body[0];

const timeline1 = new TimelineMax();

timeline1.fromTo(hero, 1, {height: "0%"}, {height: "100%", ease: Power2.easeInOut})
.fromTo(hero, 3, {width: "80%"}, {width: "100%", ease: Power2.easeInOut}, "-=3");