// xkx npc cave8 npc12.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("妙谛大师", ({"miaodi", "dashi"}));
    set("nickname", "少林长老");
    set("gender", "男性");
    set("age", 90);
    set("long", 
      "他盘坐地上，闭目凝思。\n");
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
也许是这样，不知老衲和愚茶谁对...
LONG);
}





