// xkx npc cave9 npc13.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("������", ({"ding busi", "ding"}));
    set("nickname", "һ�ղ�����");
    set("gender", "����");
    set("age", 50);
    set("long", 
      "���뷢�Ȼ��üĿ���顣\n");
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
��Ů�ӵ�����˭��
LONG);
}





