// xkx npc cave5 npc9.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("风良", ({"feng liang", "feng"}));
    set("nickname", "锦州青龙门掌门人");
    set("gender", "男性");
    set("age", 40);
    set("long", 
      "他身材高大，腰缠九节鞭.\n");
    set("attitude", "peaceful");
     

    setup();
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
我觉得应和第一室的注解一起理解，切不可断章取义。
LONG);
}





