//walker.c

inherit NPC;

void create()
{
        set_name("����", ({ "walker" }) );
	set("age", 20 + random (45));
	
        switch (random (3)) {
		case 0:
			set("gender", "Ů��");
			break;
		default:	
			set("gender", "����" );
			break;
		}

        set("combat_exp", 30000);
	if (random(4) == 0) {
		set_skill("unarmed", 40);
		set_skill("spicyclaw", 20);
		set_skill("parry", 40);
		map_skill("unarmed", "spicyclaw");
		}

        set("attitude", "friendly");
        set("chat_chance", random (20));
        set("chat_msg", ({
                "����ҡ��ҡͷ��˵�������޳���ֻ����������Щ�ϰ��ա�\n",
                "���˷߷ߵ�˵������ͷ��������Ǯ�����򵽹١��ߣ�\n",
                "����̾�˿���������̫�����ˣ���͢�����Ǹ��ϲ����İѳ��š��ȣ�\n",
		(: random_move :),
        }) );

        set("inquiry", ([
                "���" : (: "ȫ���Ǹ�������������������\n" :),
	        ]) );
        setup();
}

