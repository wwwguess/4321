// xkx npc cave2 npc6.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("西门观止", ({"ximen guanzhi", "ximen"}));
    set("nickname", "秀才");
    set("gender", "男性");
    set("age", 50);
    set("long", 
      "他身材高瘦，作书生打扮。\n");
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
这首诗含有武学至理。
LONG);
}





