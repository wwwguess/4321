// xkx npc cave24 npc3.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("木岛主", ({"island master", "mu"}));
    set("nickname", "侠客岛开山祖师");
    set("gender", "男性");
    set("age", 100);
    set("long", 
      "他显得很苍老，长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}
void init()
{
    ::init();
    call_out("greeting",1,this_player());
}

void greeting(object me)
{
    remove_call_out("greeting");
    tell_object(me,@LONG
这位英雄年纪青青，居然识得这蝌蚪文！！！
LONG);
}





