// xkx npc cave24 npc3.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("ľ����", ({"island master", "mu"}));
    set("nickname", "���͵���ɽ��ʦ");
    set("gender", "����");
    set("age", 100);
    set("long", 
      "���Եúܲ��ϣ�����ϡϡ���䣬أ�Ժڶ���٣���һ����ȴ�������ơ�\n");
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
��λӢ��������࣬��Ȼʶ��������ģ�����
LONG);
}





