// xkx npc cave11 npc14.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("÷��ܰ", ({"mei wenxin", "mei"}));
    set("nickname", "÷��ȭ����");
    set("gender", "Ů��");
    set("age", 40);
    set("long", 
      "����İ�С����������һ����ĺ�ɴ��\n");
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
��֪���������Ķ�?
LONG);
}





