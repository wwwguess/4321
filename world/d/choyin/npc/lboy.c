inherit NPC;

void create()
{
        set_name("����ͯ��", ({ "boy" }) );
        set("gender", "����" );
        set("age", 15);
        set("per", 30-random(15) );
        set("long",@LONG
����ͯ���������ص�С������С�¿��㶡��������֮��������̨��
LONG
        );
        set("combat_exp", 1200000);
        set("attitude", "friendly");
                set("chat_chance", 2);
        set("chat_msg", ({
"����ͯ�ӹ���һҾ�� \n",
"ͯ��˵�������� ��ֻ�ڴ�ɽ�У����֪����\n", 
       }) );

                set("chat_chance_combat", 10);
                set("chat_msg_combat", ({
"����ͯ��šü˵�������۸������С����\n",
"����ͯ��Ц������ɱ�����ҵġ�\n",
"����ͯ�ӳ���һ����, ˵��: ��������Ĺ��?\n",
                }) );
        set("inquiry", ([
                "����" : "ֻ����Ե�ˡ�",
        ]) );

        set_skill("dodge", 150);
        set_skill("unarmed", 150);
        set_skill("mysterrier",150); 
        map_skill("dodge", "mysterrier");
        set_skill("force", 15);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 0);
        setup();

}

