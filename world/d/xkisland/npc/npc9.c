// xkx npc cave5 npc9.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("����", ({"feng liang", "feng"}));
    set("nickname", "����������������");
    set("gender", "����");
    set("age", 40);
    set("long", 
      "����ĸߴ������Žڱ�.\n");
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
�Ҿ���Ӧ�͵�һ�ҵ�ע��һ����⣬�в��ɶ���ȡ�塣
LONG);
}





