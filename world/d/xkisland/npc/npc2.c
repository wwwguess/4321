// xkx npc cave1 npc2.c  
//dan
inherit NPC;
void consider();
void create()
{
    set_name("温仁厚", ({"wen renhou", "wen"}));
    set("nickname", "山东八仙剑掌门");
    set("gender", "男性");
    set("age", 60);
    set("long", 
      "他正在看着墙壁凝思.\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}






