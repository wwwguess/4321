// xkx npc cave1 npc1.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("ʯ����", ({"shi potian", "shi"}));
    set("nickname", "���ְ����������������");
    set("gender", "����");
    set("age", 20);
    set("long", 
      "������ȥ����ʯ����ֻ����ɫ�Ϻڣ�üë�Դ֣�\nüĿ��¶��һ��Ӣ��֮����\n");
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
�ҿ�����ǽ�ϵ��֣������ʻ���Щ�Ź֣���
��studywall ,�ƺ���Щ�ĵá�
LONG);
}





