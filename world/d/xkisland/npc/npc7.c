// xkx npc cave3 npc7.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("�������", ({"tianxu"}));
    set("nickname", "���������");
    set("gender", "����");
    set("age", 50);
    set("long", 
      "������׷����ɷ����ǡ�\n");
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
�㿴��ͼ�⣬����֮����Ӧ����ʫ��ԭּ��
LONG);
}





