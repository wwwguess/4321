// xkx npc cave8 npc12.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("���д�ʦ", ({"miaodi", "dashi"}));
    set("nickname", "���ֳ���");
    set("gender", "����");
    set("age", 90);
    set("long", 
      "���������ϣ���Ŀ��˼��\n");
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
Ҳ������������֪���ĺ��޲�˭��...
LONG);
}





