inherit NPC;

void create()
{
     set_name("�����", ({"guest"}) );
     set("gender", "����");
     set("age", 31);
     set("long", 
         "һ������̩̩��������, �����������������ʯ�ݵ�\n");
     set("combat_exp", 600);
     set("attitude", "friendly");
     setup();
     add_money("silver", 5);
}
