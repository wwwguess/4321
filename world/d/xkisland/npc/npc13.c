// xkx npc cave9 npc13.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("丁不四", ({"ding busi", "ding"}));
    set("nickname", "一日不过四");
    set("gender", "男性");
    set("age", 50);
    set("long", 
      "他须发皓然，眉目慈祥。\n");
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
那女子到底是谁？
LONG);
}





