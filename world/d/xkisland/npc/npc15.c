// xkx npc cave12-23 npc15.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("江湖豪客", ({"ke"}));
    set("gender", "男性");
    set("age", 100);
    set("long", 
      "他双目蕴含神光，武功深不可测.\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}





