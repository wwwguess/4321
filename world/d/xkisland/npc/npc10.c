// xkx npc cave6 npc10.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("��һ��", ({"fan yifei", "fan"}));
    set("nickname", "�ɶ���");
    set("gender", "����");
    set("age", 60);
    set("long", 
      "������ݸߣ���Ȼ�Ṧ�Ƿ���\n");
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
����һ�б�һ��ǰ�ɴ��н���.
LONG);
}





