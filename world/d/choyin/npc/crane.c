inherit NPC;

void create()
{
        set_name("�ɺ�",({"crane"}) );
        set("long", "������ѩ�����Ʒ���֮� \n");
        set("race", "Ұ��");
        set("unit", "ֻ");
        set("max_gin", 300);
        set("max_kee", 900);
        set("max_sen", 900);
        set("limbs", ({"��"}));
        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("env/wimpy",100);
        set_skill("parry", 10);
        set_skill("dodge", 150);
        set_skill("move", 150);
        setup();
}
 
