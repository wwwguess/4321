// xkx npc cave11 npc14.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("梅文馨", ({"mei wenxin", "mei"}));
    set("nickname", "梅花拳传人");
    set("gender", "女性");
    set("age", 40);
    set("long", 
      "她身材矮小，脸上蒙着一层厚厚的黑纱。\n");
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
不知芳姑现在哪儿?
LONG);
}





