// xkx npc cave1 npc1.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("石破天", ({"shi potian", "shi"}));
    set("nickname", "长乐帮代帮主－－狗杂种");
    set("gender", "男性");
    set("age", 20);
    set("long", 
      "他看上去酷似石中玉，只是面色较黑，眉毛稍粗，\n眉目间露出一股英侠之气。\n");
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
我看不懂墙上的字，但觉笔画有些古怪，于
是studywall ,似乎有些心得。
LONG);
}





