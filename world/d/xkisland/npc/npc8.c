// xkx npc cave4 npc8.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("高三娘子", ({"gao", "niang zhi"}));
    set("nickname", "万马庄女主人");
    set("gender", "女性");
    set("age", 30);
    set("long", 
      "她相貌寻常，平素自高自大，性如烈火，但待人极热情。\n");
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
我们不可太钻牛角尖，拘泥于诗句原意。
LONG);
}





