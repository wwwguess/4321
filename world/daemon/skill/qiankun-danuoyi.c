// qiankun-danuoyi
// yuer

inherit SKILL;

string *parry_msg = ({
	"$N����һ�Σ�$n��$v����ƫ��һ�ߡ�����б������$n�Ĺ���Ų����ж�˿�ȥ��\n",
	"$N��ָһ����$n��һ��֮�����ް������֮����\n",
	});

int valid_enable(string usage) { return (usage == "parry"); }
int valid_learn(object me) { return 1; }

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int practice_skill(object me)
{
                      return notify_fail("Ǭ����Ų�Ʋ�������\n");
               return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}


