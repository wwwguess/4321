// xkx npc cave6 npc10.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("范一飞", ({"fan yifei", "fan"}));
    set("nickname", "辽东鹤");
    set("gender", "男性");
    set("age", 60);
    set("long", 
      "他身材瘦高，现然轻功非凡。\n");
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
我这一招比一月前可大有进境.
LONG);
}





