// kuihua-shengong.c □葵花神功 
// dfbb@hero

inherit FORCE;

 string *absorb_msg = ({
        "$n身体虚转，双手微划，无坚不摧的九阳神功澎湃而出。\n",

        "$n施展出九阳神功，浑身肌肤坚如寒铁。\n",

        "$n身型微展，九阳神功充斥了丈许空间。\n",

        "$n心神一动，他强由他强，清风拂山岗，真气护满全身。\n", 

        "$n心神一动，他横由他横，明月照大江，真气护满全身。\n",

        "$n心中默念，他自狠来他自恶，我自胸中一口气。\n",
        });

int valid_enable(string usage)
{
return usage == "force" || usage == "iron-cloth";
}

int valid_learn(object me)
{
	int nf;
	nf = (int)me->query_skill("force", 1);

	if ( nf < 10)
		return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");

	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 20)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练九阳神功。\n");

	me->receive_damage("kee", 10);
	me->receive_damage("force", 10);
	return 1;
}

string exert_function_file(string func)
{
	return __DIR__"jiuyang-shengong/" + func;
}
 query_absorb_msg(string limb)
{
       return absorb_msg[random(sizeof(absorb_msg))];
}


