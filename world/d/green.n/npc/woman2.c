// Mon  08-21-95

inherit NPC;

void create()
{
        seteuid(getuid());
        set_name("����",({"woman"}));
        set("gender","Ů��");
        set("age",40);
        set("combat_exp",50);
        set_temp("apply/dodge",3);
        add_money("coin",100);
        set("chat_chance",7);
        set("chat_msg", ({
        "����˵������˵��, �ܹ����Ǽ���С��.\n",
        "����˵������֪ɽ���Ǳ��ֹ�, û�´������Ǽ��������ܹ�ȥ.\n",
        "���˴򿪹���\����һ��.\n",
        "���˳����⿴�˿�.\n",
        "����˵�����峤��ǰ������С͵, �ҿ��Ǹ�����������...\n",
        }) );
        setup();
        carry_object("/obj/cloth")->wear();
}
