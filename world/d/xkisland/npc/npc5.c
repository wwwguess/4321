// xkx npc cave10 npc5.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("������", ({"bai zizai", "bai"}));
    set("nickname", "ѩɽ�����ţ�����������");
    set("gender", "����");
    set("age", 60);
    set("long", 
      "���׷���Ȼ��ȴ����̬���͡�\n");
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
������һ��[ѩ���צ������ת���棬б���к�
�޲�һ�С�̤ѩѰ÷�����ὣ�ӳ���ն���ֱ�.
....
�����ڻӽ��й�ֱ�����Ƶ�������
�޲�ὣ����
ֻ����ž��һ����������ϡ�
����ͬʱ�˿�������
LONG);
}





