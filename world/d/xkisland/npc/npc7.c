// xkx npc cave3 npc7.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("天虚道人", ({"tianxu"}));
    set("nickname", "三清观掌门");
    set("gender", "男性");
    set("age", 50);
    set("long", 
      "他白须白发，仙风侠骨。\n");
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
你看这图解，其中之含义应不脱诗句原旨。
LONG);
}





