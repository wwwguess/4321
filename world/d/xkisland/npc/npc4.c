// xkx npc cave10 npc4.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("愚茶道人", ({"yu cha", "yu"}));
    set("nickname", "武当名宿");
    set("gender", "男性");
    set("age", 70);
    set("long", 
      "他鹤发童颜，已在侠客岛钻研武学数十年。\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}






