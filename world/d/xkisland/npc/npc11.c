// xkx npc cave7 npc11.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("����ƽ", ({"lv zhengping", "lv"}));
    set("nickname", "����ɽ�Ͽ쵶�����ˣ����Ͻ�");
    set("gender", "����");
    set("age", 40);
    set("long", 
      "��һ��������������һ����ס�\n");
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
������뿪��׵�ԭ�⣬�㲻�ɽ��ˡ�
LONG);
}





