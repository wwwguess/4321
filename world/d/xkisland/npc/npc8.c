// xkx npc cave4 npc8.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("��������", ({"gao", "niang zhi"}));
    set("nickname", "����ׯŮ����");
    set("gender", "Ů��");
    set("age", 30);
    set("long", 
      "����òѰ����ƽ���Ը��Դ������һ𣬵����˼����顣\n");
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
���ǲ���̫��ţ�Ǽ⣬������ʫ��ԭ�⡣
LONG);
}





